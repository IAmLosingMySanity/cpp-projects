#include <iostream>
#include <fstream>
#include <string.h>

const uint64_t key = 0x0123456789ABCDEF;

uint32_t TensorProduct(uint32_t A, uint32_t B) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        if ((B >> i) & 1) {
            result ^= A << i;
        }
    }

    return result;
}


uint32_t F(uint32_t L, uint64_t K) {
    uint32_t shiftedL = (L << 9) | (L >> (32 - 9));
    uint32_t tensorProduct = TensorProduct(~(K >> 11), L);

    return shiftedL ^ tensorProduct;
}


void Round(uint32_t& L, uint32_t& R, uint64_t K) {
    uint32_t temp = R;
    R = L ^ F(R, K);
    L = temp;
}


void Encrypt(uint64_t& block, uint64_t key, int numRounds) {
    uint32_t L = block >> 32;
    uint32_t R = block & 0xFFFFFFFF;

    for (int i = 0; i < numRounds; i++) {
        Round(L, R, key);
    }

    block = (static_cast<uint64_t>(L) << 32) | R;
}


void Decrypt(uint64_t& block, uint64_t key, int numRounds) {
    uint32_t L = block >> 32;
    uint32_t R = block & 0xFFFFFFFF;

    for (int i = 0; i < numRounds; i++) {
        Round(R, L, key);
    }

    block = (static_cast<uint64_t>(L) << 32) | R;
}

void PadBlock(uint64_t& block, std::streamsize bytesRead) {
    if (bytesRead < sizeof(block)) {
        uint64_t padding = 0;
        memcpy(reinterpret_cast<char*>(&block) + bytesRead, &padding, sizeof(block) - bytesRead);
    }
}

void UnpadBlock(uint64_t& block, std::streamsize& bytesRead) {
    while (bytesRead > 0 && reinterpret_cast<char*>(&block)[bytesRead - 1] == '\0') {
        --bytesRead;
    }
}

int main(int argc, char* argv[]) {

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <action>" << std::endl;
        return 1;
    }

    std::string file = argv[1];

    std::string action = argv[2];

    if (action == "e") {
        
        std::ifstream inputFile(file, std::ios::binary);
        std::ofstream outputFile("output.txt", std::ios::binary);

        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Failed to open files." << std::endl;
            return 1;
        }

        uint64_t block;
        std::streamsize bytesRead;
        while ((bytesRead = inputFile.read(reinterpret_cast<char*>(&block), sizeof(block)).gcount()) > 0) {
            PadBlock(block, bytesRead);
            Encrypt(block, key, 8);
            outputFile.write(reinterpret_cast<const char*>(&block), sizeof(block));
        }

        inputFile.close();
        outputFile.close();

        std::cout << "Encryption completed successfully." << std::endl;

        return 0;
    }

    else if (action == "d")
    {
        std::ifstream inputFile("output.txt", std::ios::binary);
        std::ofstream outputFile("decoded.txt", std::ios::binary);

        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Failed to open files." << std::endl;
            return 1;
        }

        uint64_t block;
        std::streamsize bytesRead;
        while ((bytesRead = inputFile.read(reinterpret_cast<char*>(&block), sizeof(block)).gcount()) > 0) {
            Decrypt(block, key, 8);
            UnpadBlock(block, bytesRead);
            outputFile.write(reinterpret_cast<const char*>(&block), bytesRead);
        }

        inputFile.close();
        outputFile.close();

        std::cout << "Decryption completed successfully." << std::endl;

        return 0;
    }

    else { 
        std::cerr << "Invalid action. Available actions: e (encode), d (decode)" << std::endl;
        return 1;
    }
}
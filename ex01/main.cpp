#include "Serializer.hpp"

static void printData(const std::string &label, const Data &data)
{
    std::cout << label
              << data.int_val << ", "
              << data.double_val << ", "
              << data.char_val << std::endl;
}

int main()
{
    // 1) Prepare original object
    Data originalData;
    originalData.int_val = 42;
    originalData.double_val = 3.141592;
    originalData.char_val = 'C';

    // 2) Serialize: Data* -> uintptr_t
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized: " << serialized << std::endl;

    // 3) Deserialize: uintptr_t -> Data*
    Data *deserializedData = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedData << std::endl;
    printData("Original Data: ", originalData);
    printData("Deserialized Data: ", *deserializedData);

    // 4) Verify pointer identity
    if (&originalData == deserializedData) {
        std::cout << "The pointers are the same!" << std::endl;
    } else {
        std::cout << "The pointers are different!" << std::endl;
    }

    return 0;
}


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sort.h"
#include "utiles.h"
using namespace templates;
using namespace std;

template<class T>
int func(const T *a, const T *b) {
    int64_t res = int64_t(*a) - int64_t(*b);
    if (res > 0)
        return 1;
    if (res < 0)
        return -1;
    return 0;
}

class test_class {
    private:
    char a, b;

    public:
    test_class(int input) {
        a = input % 255;
        b = input / 255;
    }
    ~test_class() = default;
    operator int() const {
        return a + b;
    }
};

TEST_CASE("merge sort sort of int array, len is 100") {

    const int len = 100;
    const int number_of_iterations = 10000;
    typedef int type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }

        CHECK(array_is_sorted);
    }
}
TEST_CASE("merge sort of int array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef int type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("merge sort sort of size_t array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef size_t type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("merge sort sort of char array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef char type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("merge sort bool of bool array, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef bool type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}

TEST_CASE("merge sort bool of long int, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef int64_t type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}

TEST_CASE("merge sort of a  class, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef test_class type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        mergeSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}

TEST_CASE("heapsort sort of int array, len is 100") {

    const int len = 100;
    const int number_of_iterations = 10000;
    typedef int type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }

        CHECK(array_is_sorted);
    }
}
TEST_CASE("heapsort sort of int array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef int type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("heapsort sort of size_t array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef size_t type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("heapsort sort of char array, len is 1000000") {

    const int len = 1000000;
    const int number_of_iterations = 10;
    typedef char type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
TEST_CASE("heapsort bool of bool array, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef bool type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}

TEST_CASE("heapsort bool of long int, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef int64_t type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}

TEST_CASE("heapsort of a  class, len is 10000") {

    const int len = 10000;
    const int number_of_iterations = 100;
    typedef test_class type;

    for (int i = 0; i < number_of_iterations; i++) {
        self_destroyed_array<type> array(len, i);
        heapSort<type>(array.get_ptr(), len, func);

        bool array_is_sorted = true;
        for (int j = 0; j < len - 1; j++) {
            if (func(array.get_ptr()[j], array.get_ptr()[j + 1]) > 0)
                array_is_sorted = false;
        }
        CHECK(array_is_sorted);
    }
}
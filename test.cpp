/*
 * MIT License
 * 
 * Copyright (c) 2021 Pavel I. Kryukov
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "patience_sort.h"

#include <iostream>
#include <list>

static bool compare(int a, int b) noexcept { return a > b; }

static bool check_cont()
{
    std::list<int> example{1, 5, 1, 5, 12, 4, 104, 15, 2, 8};
    patience_sort_cont(example.begin(), example.end());

    return std::is_sorted(example.begin(), example.end());
}

static bool check_inverse()
{
    std::list<int> example{1, 5, 1, 5, 12, 4, 104, 15, 2, 8};
    patience_sort_cont(example.begin(), example.end(), compare);

    return std::is_sorted(example.begin(), example.end(), compare);
}

static bool check_list()
{
    std::list<int> example{1, 5, 1, 5, 12, 4, 104, 15, 2, 8};
    patience_sort_list(example.begin(), example.end());

    return std::is_sorted(example.begin(), example.end());
}

static bool check_list_inplace()
{
    std::list<int> example{1, 5, 1, 5, 12, 4, 104, 15, 2, 8};
    patience_sort(example, compare);

    return std::is_sorted(example.begin(), example.end(), compare);
}

int main()
{
    for (auto f : {check_cont, check_list, check_list_inplace, check_inverse}) {
        bool result = f();
        if (!result) {
            std::cout << "Failure\n";
            return 1;
        }
    }

    std::cout << "Success\n";
    return 0;
}

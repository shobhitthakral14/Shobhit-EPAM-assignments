// | **Category**              | **Algorithm**                               | **Description**                                  | **Iterator Required** | **Time Complexity** |
// | ------------------------- | ------------------------------------------- | ------------------------------------------------ | --------------------- | ------------------- |
// | **Non-modifying**         | `find`, `find_if`                           | Find element or condition                        | Input                 | O(N)                |
// |                           | `count`, `count_if`                         | Count occurrences                                | Input                 | O(N)                |
// |                           | `all_of`, `any_of`, `none_of`               | Logical checks on range                          | Input                 | O(N)                |
// |                           | `for_each`                                  | Applies function to each element                 | Input                 | O(N)                |
// |                           | `mismatch`, `equal`                         | Compare two ranges                               | Forward               | O(N)                |
// |                           | `search`, `find_end`                        | Find subsequence                                 | Forward               | O(N\*M)             |
// | **Modifying**             | `copy`, `copy_if`                           | Copy elements (with condition)                   | Input → Output        | O(N)                |
// |                           | `move`                                      | Move elements                                    | Input → Output        | O(N)                |
// |                           | `replace`, `replace_if`                     | Replace values                                   | Forward               | O(N)                |
// |                           | `fill`, `fill_n`                            | Assign a value to range                          | Output                | O(N)                |
// |                           | `generate`, `generate_n`                    | Fill range using generator                       | Output                | O(N)                |
// |                           | `remove`, `remove_if`                       | Shift non-matching elements                      | Forward               | O(N)                |
// |                           | `unique`                                    | Remove consecutive duplicates (returns new end)  | Forward               | O(N)                |
// |                           | `transform`                                 | Apply function and assign to new range           | Input → Output        | O(N)                |
// | **Sorting**               | `sort`                                      | Sorts in ascending (default)                     | Random Access         | O(N log N)          |
// |                           | `stable_sort`                               | Like `sort` but preserves order                  | Random Access         | O(N log² N)         |
// |                           | `partial_sort`                              | Sorts first N elements                           | Random Access         | O(N log K)          |
// |                           | `nth_element`                               | Partially sorts so nth element is in correct pos | Random Access         | O(N) avg            |
// |                           | `is_sorted`, `is_sorted_until`              | Checks if sorted                                 | Forward               | O(N)                |
// |                           | `binary_search`                             | Checks if element exists (sorted range)          | Random Access         | O(log N)            |
// |                           | `lower_bound`, `upper_bound`, `equal_range` | Binary search helpers                            | Random Access         | O(log N)            |
// | **Partitioning**          | `partition`                                 | Splits range into true/false by predicate        | Bidirectional         | O(N)                |
// |                           | `stable_partition`                          | Like `partition`, maintains order                | Bidirectional         | O(N log N)          |
// |                           | `partition_point`                           | Finds split point                                | Forward               | O(log N)            |
// |                           | `is_partitioned`                            | Checks if already partitioned                    | Forward               | O(N)                |
// | **Set Operations**        | `set_union`                                 | Union of sorted ranges                           | Input                 | O(N)                |
// |                           | `set_intersection`                          | Common elements                                  | Input                 | O(N)                |
// |                           | `set_difference`                            | A - B (sorted)                                   | Input                 | O(N)                |
// |                           | `set_symmetric_difference`                  | Elements in A or B but not both                  | Input                 | O(N)                |
// |                           | `includes`                                  | Check if one sorted range contains another       | Input                 | O(N)                |
// | **Heap Operations**       | `make_heap`                                 | Converts to heap                                 | Random Access         | O(N)                |
// |                           | `push_heap`, `pop_heap`                     | Insert/remove in heap                            | Random Access         | O(log N)            |
// |                           | `sort_heap`                                 | Sorts heap                                       | Random Access         | O(N log N)          |
// |                           | `is_heap`, `is_heap_until`                  | Checks heap property                             | Random Access         | O(N)                |
// | **Min/Max & Permute**     | `min`, `max`, `minmax`                      | Find min/max values                              | -                     | O(1)                |
// |                           | `min_element`, `max_element`                | Find iterators to min/max in range               | Forward               | O(N)                |
// |                           | `next_permutation`, `prev_permutation`      | Rearrange to next/prev lexicographic order       | Bidirectional         | O(N)                |
// | **Numeric** (`<numeric>`) | `accumulate`                                | Sum or combine elements                          | Input                 | O(N)                |
// |                           | `inner_product`                             | Dot product                                      | Input                 | O(N)                |
// |                           | `partial_sum`                               | Running sum (prefix sum)                         | Input                 | O(N)                |
// |                           | `adjacent_difference`                       | Difference between consecutive elements          | Input                 | O(N)                |


#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Alice", 25}, {"Bob", 25}, {"Charlie", 20}
    };

    std::stable_sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
        return a.age < b.age;
    });

    for (auto &p : people)
        std::cout << p.name << " ";
}

import time


def binary_search(arr, start, end, val):
    while start <= end:
        mid = (start + end)//2
        if arr[mid] == val:
            return mid
        # val might be in right side
        elif arr[mid] < val:
            start = mid + 1
        # val might be on left
        else:
            end = mid - 1
    # value not found
    return -1


def one_dimension_test(size):
    first = []
    # create & fill array of specified size
    for i in range(size):
        first.append(i+1)
    # always look for val 500
    start = time.time_ns()
    binary_search(first, 0, len(first)-1, 500)
    end = time.time_ns()
    total = end - start
    return total


def average_one_dimension():
    test_values = (30000000, 15000000, 7500000, 3750000, 1875000)
    for val in test_values:
        sum_of_run = 0
        for i in range(10):
            sum_of_run += one_dimension_test(val)
            if i == 9:
                print("Average of 10 runs for one-dimensional array of size", val, ":", sum_of_run/10, "nanoseconds")


average_one_dimension()

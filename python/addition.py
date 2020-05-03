import time


def one_dimension():
    result = []
    size = 29997529
    first = [5] * size
    second = [2] * size
    start = time.time_ns()
    for i in range(size):
        result.append(first[i] + second[i])
    end = time.time_ns()
    total = end - start
    return total


def average_one_dimension():
    sum_of_run = 0
    for i in range(10):
        sum_of_run += one_dimension()
    return sum_of_run/10


print("Average of 10 runs for one-dimensional array:", average_one_dimension(), "nanoseconds")


def multi_dimension():
    result = []
    size = 5477
    rows, cols = (size, size)
    first = [[5] * cols] * rows
    second = [[2] * cols] * rows
    start = time.time_ns()
    for j in range(size):
        temp = []
        for i in range(size):
            temp.append(first[j][i]+second[j][i])
        result.append(temp)
    end = time.time_ns()
    total = end - start
    return total


def average_multi_dimension():
    sum_of_run = 0
    for i in range(10):
        sum_of_run += multi_dimension()
    return sum_of_run/10


print("Average of 10 runs for multi-dimensional array:", average_multi_dimension(), "nanoseconds")

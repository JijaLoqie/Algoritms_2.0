def bin_search(v, x):
    l, r = 0, len(v) - 1
    while (l < r):
        mid = (l + r) // 2
        if (v[mid] < x):
            l = mid + 1
        elif (v[mid] >= x):
            r  = mid
    return r

def main():
    n, x = map(int, input().split(' '))
    v = list(map(int, input().split(' ')))
    print(bin_search(v, x))

if __name__ == "__main__":
    main()
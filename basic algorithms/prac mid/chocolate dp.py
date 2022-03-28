def maxprice(p, num_row, num_col):
    memo = [[0] * num_col for _ in range(num_row)]
    for i in range(1, num_row):
        for j in range(1, num_col):
            for hori_cut in range(i):
                memo[i][j] = max(memo[i][j], p[hori_cut][j] + memo[i - hori_cut][j])
            for vert_cut in range(j):
                memo[i][j] = max(memo[i][j], p[i][vert_cut] + memo[i][j - vert_cut])
    return memo[num_row - 1][num_col - 1]

price = [[1, 2, 3],
        [4, 5, 6]]
ret = maxprice(price, len(price), len(price[0]))
print(ret)

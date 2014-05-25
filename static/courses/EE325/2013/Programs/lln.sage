def uniform_lln(n, a, b):
    T = RealDistribution('uniform', [a, b])
    partial_sum = 0
    partial_sum_vector = []
    for i  in range(1, n):
        partial_sum += T.get_random_element()
        partial_sum_vector.append(partial_sum/i)

    p1 = line(zip(range(1, n), partial_sum_vector), ymin = a, ymax = b)
    p2 = plot((a+b)/2, (0, n), color = 'red')
    plt = p1 + p2
    plt.axes_labels(['$n$', '$S_n/n$'])
    show(plt)

def bernoulli_lln(n, p):
    T = GeneralDiscreteDistribution([1-p, p])
    partial_sum = 0
    partial_sum_vector = []
    for i  in range(1, n):
        partial_sum += T.get_random_element()
        partial_sum_vector.append(partial_sum/i)

    p1 = line(zip(range(1, n), partial_sum_vector), ymin = 0, ymax = 1)
    p2 = plot(p, (0, n), color = 'red')
    plt = p1 + p2
    plt.axes_labels(['$n$', '$S_n/n$'])
    show(plt)



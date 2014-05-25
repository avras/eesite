import numpy

def uniform_clt(n, a, b, numSamples):
    T = RealDistribution('uniform', [a, b])
    var = ((b-a)^2)/12
    sample_vector = []
    for _ in range(numSamples):
        partial_sum = sum([T.get_random_element() for i in range(1,n)])
        sample_vector.append((partial_sum - n*(a+b)/2)/sqrt(n*var))

    hist, bins = numpy.histogram(sample_vector, bins = 50)
    plt = bar_chart(hist)
    show(plt)

def bernoulli_clt(n, p, numSamples):
    T = GeneralDiscreteDistribution([1-p, p])
    sample_vector = []
    for _ in range(numSamples):
        partial_sum = sum([T.get_random_element() for i in range(1,n)])
        sample_vector.append((partial_sum - n*p)/sqrt(n*p*(1-p)))

    hist, bins = numpy.histogram(sample_vector, bins = 100)
    print hist
    plt = bar_chart(hist)
    show(plt)



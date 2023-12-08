import matplotlib.pyplot as plt

# Your data
input_sizes = [10, 100, 1000]
times = [0.6, 11, 150]  # Replace with your average times

plt.plot(input_sizes, times, marker='o')

plt.xlabel('Input Size')
plt.ylabel('Time')
plt.title('Execution Time vs Input Size')

plt.show()

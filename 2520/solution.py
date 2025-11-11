class Solution:
    def countDigits(self, num: int) -> int:
        # copying the input
        number = num
        count = 0

        while (number > 0):
            # extract last digit with % operator
            lastDigit = number % 10
            if (num % lastDigit == 0):
                count += 1
            # eleminate lastDigit by floor division with 10
            number = number // 10

        return count

if __name__ == '__main__':
    solver = Solution()
    test_cases = [7, 121, 1248]
    for num in test_cases:
        print(f"For num = {num}, the number of digits that divide it is: {solver.countDigits(num)}")
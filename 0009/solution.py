class Solution:
    def isPalindrome(self, x: int) -> bool:
        # manually reverting number by extracting each digit
        tempNum = x
        reverseNum = 0
        while (tempNum > 0):
            lastDigit = tempNum % 10
            # adding lastDigit to reverseNum
            reverseNum = (reverseNum * 10) + lastDigit
            tempNum = tempNum // 10
        # return the boolean value: x (original number) == reverseNum
        return x == reverseNum

if __name__ == '__main__':
    solver = Solution()
    test_cases = [121, -121, 10, 12321]
    for x in test_cases:
        print(f"For x = {x}, isPalindrome is: {solver.isPalindrome(x)}")

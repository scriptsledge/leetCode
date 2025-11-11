class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        # Count of unmatched opening parentheses needing closing brackets
        unmatched_open = 0
        
        # Count of unmatched closing parentheses needing opening brackets  
        unmatched_close = 0
        
        for char in s:
            if char == '(':
                # Each opening bracket needs a matching closing bracket
                unmatched_open += 1
            else:  # char == ')'
                if unmatched_open > 0:
                    # Match with previous unmatched opening bracket
                    unmatched_open -= 1
                else:
                    # No matching opening bracket, need to add one before
                    unmatched_close += 1
        
        # Total moves = unmatched opening + unmatched closing brackets needed
        return unmatched_open + unmatched_close

if __name__ == '__main__':
    solver = Solution()
    test_cases = ["())", "(((", "()", "()))(("]
    for s in test_cases:
        print(f"For s = '{s}', the minimum additions to make it valid is: {solver.minAddToMakeValid(s)}")

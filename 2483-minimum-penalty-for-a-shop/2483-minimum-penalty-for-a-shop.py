class Solution:
    def bestClosingTime(self, customers: str) -> int:
        cur_penalty = 0
        min_penalty = 0
        best_hour = 0

        for i,ch in enumerate(customers):
            if ch == 'Y':
                cur_penalty -= 1
            else:
                cur_penalty += 1

            if cur_penalty<min_penalty:
                min_penalty = cur_penalty
                best_hour = i + 1
        return best_hour
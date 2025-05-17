import math
from typing import List

class Solution:
    def time_is_sufficient(self, ranks: List[int], cars: int, min_given: int) -> bool:
        cars_done = 0
        for r in ranks:
            c2 = min_given // r
            c = int(math.isqrt(c2))  # equivalent to floor(sqrt(c2))
            cars_done += c
        return cars_done >= cars

    def repairCars(self, ranks: List[int], cars: int) -> int:
        left = 1
        right = int(1e14)
        while left < right:
            mid = (left + right) // 2
            if self.time_is_sufficient(ranks, cars, mid):
                right = mid
            else:
                left = mid + 1
        return left

# 🔹 Example usage
if __name__ == "__main__":
    solution = Solution()
    ranks = [4, 2, 3, 1]  # Example input
    cars = 10
    print("Minimum time to repair cars:", solution.repairCars(ranks, cars))

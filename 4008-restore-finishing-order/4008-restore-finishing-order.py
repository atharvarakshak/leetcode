class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        return [ order[i]  for i in range(len(order)) if order[i] in friends]
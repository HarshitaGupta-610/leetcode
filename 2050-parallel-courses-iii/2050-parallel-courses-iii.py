class Solution:
    def minimumTime(self, n: int, relations: list[list[int]], time: list[int]) -> int:
        graph=[[]for _ in range(n+1)]
        in_degree = [0] * (n+1)

        for u ,v in relations:
            graph[u].append(v)
            in_degree[v] += 1

        finish_time = [0]+time[:]

        queue = deque([i for i in range (1, n+1) if in_degree[i] == 0])
        while queue:
            curr = queue.popleft()
            for neighbor in graph[curr]:
                finish_time[neighbor] = max(finish_time[neighbor] , finish_time[curr] + time[neighbor - 1] )
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
        return max(finish_time)
        
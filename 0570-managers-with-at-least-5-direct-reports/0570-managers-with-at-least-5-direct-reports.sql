# Write your MySQL query statement below
-- e1 represents managers
-- e2 represents employees
SELECT e1.name
FROM Employee e1

-- Match each manager with their employees
JOIN Employee e2
ON e1.id = e2.managerId

-- Create one group for each manager
GROUP BY e1.id, e1.name

-- Keep only managers having at least 5 direct reports
HAVING COUNT(*) >= 5;
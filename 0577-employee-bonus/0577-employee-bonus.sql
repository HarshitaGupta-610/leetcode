# Write your MySQL query statement below
SELECT Employee.name , Bonus.bonus
FROM Employee 
LEFT JOIN BONUS
ON Employee.empId = Bonus.empId
WHERE Bonus.bonus < 1000  OR Bonus.bonus is NULL;
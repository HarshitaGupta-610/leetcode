# Write your MySQL query statement below
select Employee.name , Bonus.bonus
from Employee
left Join Bonus
ON Employee.empId = Bonus.empId
where bonus < 1000 
OR bonus is NULL;

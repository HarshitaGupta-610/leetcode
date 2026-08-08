# Write your MySQL query statement below
select Project.project_id,
round(avg(Employee.experience_years), 2) as average_years
from Project
join Employee
ON Project.employee_id = Employee.employee_id
Group by Project.project_id;



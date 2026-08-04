# Write your MySQL query statement below
select customer_id,
 count(*) as count_no_trans
from visits
left join Transactions
on Visits.visit_id = Transactions.visit_id
WHERE  transaction_id is NULL
group by customer_id;

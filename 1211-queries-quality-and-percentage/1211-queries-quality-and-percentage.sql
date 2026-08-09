# Write your MySQL query statement below
select query_name,
round(avg(rating/position),2
) as quality,
ROUND(AVG(CASE
    WHEN rating < 3 THEN 1
    ELSE 0
    END
        ) * 100,
        2
    ) AS poor_query_percentage
From Queries
Group By query_name;
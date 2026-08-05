# Write your MySQL query statement below
-- We need to compare today's weather with yesterday's weather.
-- Since both records are in the SAME table, we create TWO copies of the Weather table.
-- w1 = Today's weather
-- w2 = Yesterday's weather
-- We need to compare today's weather with yesterday's weather.
-- Since both records are in the SAME table, we create TWO copies of the Weather table.
-- w1 = Today's weather
-- w2 = Yesterday's weather

SELECT w1.id
FROM Weather w1
-- Self Join: Joining the Weather table with itself
JOIN Weather w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;
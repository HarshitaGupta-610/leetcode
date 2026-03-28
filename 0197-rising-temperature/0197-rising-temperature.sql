SELECT Weather.id
FROM Weather
JOIN Weather AS prev
ON DATEDIFF(Weather.recordDate, prev.recordDate) = 1
WHERE Weather.temperature > prev.temperature;
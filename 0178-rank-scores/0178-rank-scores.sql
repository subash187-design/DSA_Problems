# Write your MySQL query statement below
SELECT score,rk as 'Rank'
FROM (
    SELECT score,
    DENSE_RANK() over(
        ORDER BY score DESC
    ) AS rk
    FROM Scores
) AS temp;
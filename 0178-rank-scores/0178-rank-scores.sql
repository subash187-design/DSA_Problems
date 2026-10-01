# Write your MySQL query statement below
SELECT *
FROM (
    SELECT score,
    DENSE_RANK() over(
        ORDER BY score DESC
    ) AS 'rank'
    FROM Scores
) AS temp;
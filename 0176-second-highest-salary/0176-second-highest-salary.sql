SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT id,salary,
    DENSE_RANK() over(
        ORDER BY salary DESC
    ) AS dense_rk
    FROM Employee
)AS nthHighest
WHERE dense_rk = 2;
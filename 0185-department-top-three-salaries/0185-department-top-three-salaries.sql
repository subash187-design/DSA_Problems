# Write your MySQL query statement below
SELECT Department,Employee,Salary
FROM(
        SELECT d.name AS Department,e.name AS Employee,e.salary AS Salary,
        DENSE_RANK() over(
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        )AS rk
        FROM Employee e
        JOIN Department d ON e.departmentId = d.id
)AS temp
WHERE rk <= 3;
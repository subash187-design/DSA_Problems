SELECT DISTINCT(email) AS EMAIL
FROM Person p1
WHERE email IN (
    SELECT email
    FROM Person p2
    WHERE p1.id <> p2.id
);
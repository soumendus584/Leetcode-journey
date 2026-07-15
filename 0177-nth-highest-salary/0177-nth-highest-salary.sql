CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        SELECT DISTINCT Salary
        FROM Employee e1
        WHERE @N = (
            SELECT COUNT(DISTINCT Salary)
            FROM Employee e2
            WHERE e2.Salary >= e1.Salary
        )
    );
END
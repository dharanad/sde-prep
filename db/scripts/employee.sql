-- query all employee
SELECT
    *
FROM
    employees;

-- find employee with min salary
SELECT
    first_name || ' ' || last_name as full_name,
    salary
FROM
    employees
WHERE
    salary = (SELECT MIN(salary) FROM employees);

-- find employee with max salary
SELECT
            first_name || ' ' || last_name as full_name,
            salary
FROM
    employees
WHERE
        salary = (SELECT MIN(salary) FROM employees);

-- find employee with salary >= AVG SALARY
SELECT
            first_name || ' ' || last_name as full_name,
            salary
FROM
    employees
WHERE
        salary >= (SELECT AVG(salary) FROM employees);

-- find all employee with top 3 salaries

-- Working
SELECT
            first_name || ' ' || last_name as full_name,
            salary
FROM
    employees e1
WHERE
    (SELECT count(DISTINCT e2.salary) FROM employees e2 where e2.salary >= e1.salary) <= 3;

SELECT
            first_name || ' ' || last_name as full_name,
            salary
FROM
    employees e1
WHERE
    e1.salary in (select distinct e2.salary from employees e2 order by e2.salary desc limit 3);

-- doesnt work when there are no top 3 salaries
SELECT
            first_name || ' ' || last_name as full_name,
            salary
FROM
    employees e1
WHERE
    e1.salary >= (select distinct e2.salary from employees e2 order by e2.salary desc limit 1 offset 2);
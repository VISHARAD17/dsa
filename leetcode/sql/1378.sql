/* 1378.Replace Employee ID with the unique identifier */

select e2.unique_id, e1.name from Employees e1 left join EmployeeUNI e2 on e2.id = e1.id

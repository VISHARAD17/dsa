select email as "Email" from person GROUP BY email having count(email) > 1

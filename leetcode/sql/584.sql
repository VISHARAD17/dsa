/* 584. Find Customer Referee */ 


SELECT c.name from customer c where c.referee_id <> 2 or c.referee_id is NULL;

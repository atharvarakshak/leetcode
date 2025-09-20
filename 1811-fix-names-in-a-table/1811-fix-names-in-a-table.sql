# Write your MySQL query statement below
select user_id, 
CONCAT(UPPER(Left(name,1)),LOWER(Right(name,Length(name)-1))) as name
from  Users
order by user_id
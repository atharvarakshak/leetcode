# Write your MySQL query statement below
select  LEFT(trans_date, 7) as month,
country,
count(id) as trans_count,
sum(case when state="approved" then 1 else 0 end) as approved_count,
sum(amount) as trans_total_amount,
sum(case when state="approved" then amount else 0 end) as approved_total_amount
from Transactions
group by month,country
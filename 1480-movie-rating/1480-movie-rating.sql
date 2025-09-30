# Write your MySQL query statement below
(select u.name as results
from  MovieRating m join  Users u 
on u.user_id = m.user_id
group by u.user_id
order by count(*) desc, name asc
limit 1)
union 
(
    select title as results
    from MovieRating m join Movies mv
    on m.movie_id = mv.movie_id
    where extract(Year_Month from m.created_at) = 202002
    group by mv.movie_id
    order by AVG(m.rating) desc, title
    limit 1
);
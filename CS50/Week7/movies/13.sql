SELECT DISTINCT(name) FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN (
    SELECT movie_id FROM stars
    JOIN people ON people.id = stars.person_id
    WHERE name = 'Kevin Bacon'
    AND birth = 1958
)
AND name != 'Kevin Bacon';

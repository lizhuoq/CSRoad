-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


SELECT * FROM interviews
WHERE month = 7
AND day = 28;
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.


SELECT license_plate FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25;
-- +---------------+
-- | license_plate |
-- +---------------+
-- | 5P2BI95       |
-- | 94KL13X       |
-- | 6P58WS2       |
-- | 4328GD8       |
-- | G412CB7       |
-- | L93JTIZ       |
-- | 322W7JE       |
-- | 0NTHK55       |
-- +---------------+


SELECT * FROM atm_transactions
WHERE month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+


SELECT * FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60;
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+


SELECT * FROM flights
WHERE month = 7
AND day = 29
AND origin_airport_id = (
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour;
-- id = 36


SELECT person_id FROM bank_accounts
WHERE account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
);
-- +-----------+
-- | person_id |
-- +-----------+
-- | 686048    |
-- | 514354    |
-- | 458378    |
-- | 395717    |
-- | 396669    |
-- | 467400    |
-- | 449774    |
-- | 438727    |
-- +-----------+


SELECT passport_number FROM people
WHERE id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
);
-- +-----------------+
-- | passport_number |
-- +-----------------+
-- | 9878712108      |
-- | 7049073643      |
-- | 9586786673      |
-- | 1988161715      |
-- | 4408372428      |
-- | 8496433585      |
-- | 3592750733      |
-- | 5773159633      |
-- +-----------------+

SELECT * FROM passengers
WHERE passport_number IN (
    SELECT passport_number FROM people
    WHERE id IN (
        SELECT person_id FROM bank_accounts
        WHERE account_number IN (
            SELECT account_number FROM atm_transactions
            WHERE month = 7
            AND day = 28
            AND atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw'
        )
    )
)
AND flight_id = 36;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+


SELECT * FROM people
WHERE passport_number IN (
    SELECT passport_number FROM passengers
    WHERE passport_number IN (
        SELECT passport_number FROM people
        WHERE id IN (
            SELECT person_id FROM bank_accounts
            WHERE account_number IN (
                SELECT account_number FROM atm_transactions
                WHERE month = 7
                AND day = 28
                AND atm_location = 'Leggett Street'
                AND transaction_type = 'withdraw'
            )
        )
    )
    AND flight_id = 36
)
AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
);
-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+-------+----------------+-----------------+---------------+


SELECT city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE id = 36
);
-- +---------------+
-- |     city      |
-- +---------------+
-- | New York City |
-- +---------------+


-- (375) 555-8161
SELECT * FROM people
WHERE phone_number = '(375) 555-8161';

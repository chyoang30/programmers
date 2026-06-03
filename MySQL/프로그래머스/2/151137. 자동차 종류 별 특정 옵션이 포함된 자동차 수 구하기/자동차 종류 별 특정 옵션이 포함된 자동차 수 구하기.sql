-- 테이블: CAR_RENTAL_COMPANY_CAR
-- 속성: CAR_ID, CAR_TYPE, DAILY_FEE, OPTIONS
-- 자동차 종류: '세단', 'SUV', '승합차', '트럭', '리무진'
-- 옵션: '주차감지센서', '스마트키', '네비게이션', '통풍시트', '열선시트', '후방카메라', '가죽시트' 

SELECT CAR_TYPE, COUNT(*) AS CARS
FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS LIKE '%통풍시트%' OR OPTIONS LIKE '%열선시트%' OR OPTIONS LIKE '%가죽시트%'
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE ASC
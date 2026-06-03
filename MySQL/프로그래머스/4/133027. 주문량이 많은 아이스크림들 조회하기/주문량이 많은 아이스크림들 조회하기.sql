-- 상반기 주문 정보 테이블: FIRST_HALF -> SHIPMENT_ID: 출하번호(JULY의 외래키), FLAVOR: 맛(기본키), TOTAL_ORDER: 상반기 총 주문량
-- 7월 아이스크림 주문 정보 테이블: JULY ->SHIPMENT_ID: 출하번호(기본키), FLAVOR: 맛(외래키), TOTAL_ORDER: 7월 총 주문량

-- 7월에는 아이스크림 주문량이 많아 같은 아이스크림에 대하여 서로 다른 두 공장에서 아이스크림 가게로 출하를 진행하는 경우가 있습니다. 이 경우 같은 맛의 아이스크림이라도 다른 출하 번호를 갖게 됩니다.
-- 7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 큰 순서대로 상위 3개의 맛을 조회하는 SQL 문을 작성해주세요.

SELECT F.FLAVOR
FROM FIRST_HALF F
JOIN (
    SELECT
        FLAVOR,
        SUM(TOTAL_ORDER) AS JULY_ORDER
    FROM JULY
    GROUP BY FLAVOR
) J
ON F.FLAVOR = J.FLAVOR
ORDER BY F.TOTAL_ORDER+J.JULY_ORDER DESC
LIMIT 3;
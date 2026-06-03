-- 다음은 종합병원의 진료 예약정보를 담은 APPOINTMENT 테이블 입니다.
-- APPOINTMENT 테이블은 다음과 같으며 APNT_YMD, APNT_NO, PT_NO, MCDP_CD, MDDR_ID, APNT_CNCL_YN, APNT_CNCL_YMD는 각각 진료예약일시, 진료예약번호, 환자번호, 진료과코드, 의사ID, 예약취소여부, 예약취소날짜를 나타냅니다.

-- APPOINTMENT 테이블에서 2022년 5월에 예약한 환자 수를 진료과코드 별로 조회하는 SQL문을 작성
-- 컬럼명은 '진료과 코드', '5월예약건수'로 지정
-- 결과는 진료과별 예약한 환자 수를 기준으로 오름차순 정렬
-- 예약한 환자 수가 같다면 진료과 코드를 기준으로 오름차순 정렬

SELECT MCDP_CD AS '진료과 코드', COUNT(*) AS '5월예약건수'
FROM APPOINTMENT
WHERE MONTH(APNT_YMD)=5 AND YEAR(APNT_YMD)=2022
GROUP BY MCDP_CD
ORDER BY COUNT(*) ASC, MCDP_CD ASC
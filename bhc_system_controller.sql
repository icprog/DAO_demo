DROP TABLE IF EXISTS tb_car_nu_map;
CREATE TABLE tb_car_nu_map (
	  car_name VARCHAR2(6) NOT NULL ON CONFLICT FAIL PRIMARY KEY, 
	  car_nu_l INT, 
	  car_nu_g INT);

DROP TABLE IF EXISTS tb_car_info;
CREATE TABLE tb_car_info (
	  car_name VARCHAR2(6) NOT NULL ON CONFLICT FAIL PRIMARY KEY, 
	  slm1 CHAR(4), 
	  slm2 CHAR(4));


CREATE DATABASE  IF NOT EXISTS `livealone` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `livealone`;
-- MySQL dump 10.13  Distrib 5.7.9, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: livealone
-- ------------------------------------------------------
-- Server version	5.7.9-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `info_board`
--

DROP TABLE IF EXISTS `info_board`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `info_board` (
  `iHead` varchar(20) NOT NULL,
  `iNum` int(11) NOT NULL,
  `iTitle` varchar(50) NOT NULL,
  `iContent` varchar(1000) NOT NULL,
  `iDatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `attachFilePath` varchar(50) DEFAULT NULL,
  `UID` varchar(15) NOT NULL,
  PRIMARY KEY (`iNum`),
  KEY `UID` (`UID`),
  CONSTRAINT `info_board_ibfk_1` FOREIGN KEY (`UID`) REFERENCES `user` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `info_board`
--

LOCK TABLES `info_board` WRITE;
/*!40000 ALTER TABLE `info_board` DISABLE KEYS */;
INSERT INTO `info_board` VALUES ('인테리어',1,'펭귄1','펭귄1','2015-12-14 13:00:39','Penguins.jpg','test'),('청소',2,'펭귄2','펭귄2','2015-12-14 13:00:39','Penguins.jpg','test'),('제테크',3,'펭귄3','펭귄3','2015-12-14 13:00:39','Penguins.jpg','test'),('중고물품',4,'펭귄4','펭귄4','2015-12-14 13:00:39','Penguins.jpg','test'),('요리',5,'펭귄5','펭귄5','2015-12-14 13:00:39','Penguins.jpg','test'),('인테리어',6,'펭귄6','펭귄6','2015-12-14 13:00:39','Penguins.jpg','test'),('애완동물',7,'펭귄7','펭귄7','2015-12-14 13:00:39','Penguins.jpg','test'),('부동산',8,'펭귄8','펭귄8','2015-12-14 13:00:39','Penguins.jpg','test'),('부동산',9,'펭귄9','펭귄9','2015-12-14 13:00:39','Penguins.jpg','test'),('요리',10,'펭귄10','펭귄','2015-12-14 13:07:17','Penguins.jpg','test');
/*!40000 ALTER TABLE `info_board` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `memo`
--

DROP TABLE IF EXISTS `memo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `memo` (
  `mNum` int(11) NOT NULL,
  `mContent` varchar(50) NOT NULL,
  `mDatetime` datetime DEFAULT NULL,
  `latitude` double NOT NULL,
  `longitude` double NOT NULL,
  `UID` varchar(15) NOT NULL,
  PRIMARY KEY (`mNum`),
  KEY `UID` (`UID`),
  CONSTRAINT `memo_ibfk_1` FOREIGN KEY (`UID`) REFERENCES `user` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `memo`
--

LOCK TABLES `memo` WRITE;
/*!40000 ALTER TABLE `memo` DISABLE KEYS */;
INSERT INTO `memo` VALUES (1,'경복궁에 다녀왔어요~','2015-12-14 20:29:15',37.577156883482445,126.9770622253418,'test'),(2,'해수욕하러 경포대왔어요~','2015-12-14 20:30:21',37.80480106593472,128.90803984191734,'test'),(3,'방금 화정터미널 지나간 여자분 혹시 남자친구 있으신가요?','2015-12-14 20:43:45',37.633973699100814,126.83266753956559,'test'),(4,'기차타고 전주역이에요 전주 한옥마을 놀러왔어요','2015-12-14 21:00:29',35.849498707936114,127.16148984327447,'test'),(5,'일산 킨텍스에 디저트박람회 보러왔어요~','2015-12-14 21:20:47',37.669768485981905,126.74329118948663,'test'),(6,'강남대학교 다니시는분?? 계실까요','2015-12-14 21:22:08',37.27515925385927,127.1324200645904,'test'),(7,'경전철타고 에버랜드 왔어요~','2015-12-14 21:22:55',37.28524593729493,127.21950430859579,'test'),(8,'롯데월드 와서 바이킹 탔어요~','2015-12-14 21:24:01',37.50866642946287,127.0998833644262,'test'),(9,'강화도 팬션에 놀러왔다가 후라이팬 태워먹었어요','2015-12-14 21:27:10',37.70992650909544,126.45227281842381,'test'),(10,'만화책보러 안양역왔어요','2015-12-14 21:28:46',37.40164027004386,126.92260029281897,'test');
/*!40000 ALTER TABLE `memo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `region_board`
--

DROP TABLE IF EXISTS `region_board`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `region_board` (
  `rHead` varchar(20) NOT NULL,
  `rNum` int(11) NOT NULL,
  `rTitle` varchar(50) NOT NULL,
  `rContent` varchar(1000) NOT NULL,
  `rDatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `attachFilePath` varchar(50) DEFAULT NULL,
  `UID` varchar(15) NOT NULL,
  PRIMARY KEY (`rNum`),
  KEY `UID` (`UID`),
  CONSTRAINT `region_board_ibfk_1` FOREIGN KEY (`UID`) REFERENCES `user` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `region_board`
--

LOCK TABLES `region_board` WRITE;
/*!40000 ALTER TABLE `region_board` DISABLE KEYS */;
INSERT INTO `region_board` VALUES ('서울',1,'사막1','사막1','2015-12-14 13:08:17','Desert.jpg','test'),('서울',2,'사막2','사막2','2015-12-14 18:28:14','Desert.jpg','test'),('강원',3,'사막3','사막3','2015-12-14 13:08:17','Desert.jpg','test'),('충청',4,'사막4','사막4','2015-12-14 13:08:17','Desert.jpg','test'),('전라',5,'사막5','사막5','2015-12-14 13:08:17','Desert.jpg','test'),('경상',6,'사막6','사막6','2015-12-14 13:08:17','Desert.jpg','test'),('제주',7,'사막7','사막7','2015-12-14 13:08:17','Desert.jpg','test'),('기타',8,'사막8','사막78','2015-12-14 13:08:17','Desert.jpg','test'),('서울',9,'사막9','사막9','2015-12-14 13:08:17','Desert.jpg','test'),('서울',10,'사막10','사막10','2015-12-14 18:28:14','Desert.jpg','test');
/*!40000 ALTER TABLE `region_board` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `ID` varchar(15) NOT NULL,
  `PW` varchar(15) NOT NULL,
  `sex` char(2) NOT NULL,
  `email` varchar(30) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('test','test','남','test@test.com'),('test1','test1','여','test1@test.com');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-12-15  4:26:18

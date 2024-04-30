/*
 Navicat Premium Data Transfer

 Source Server         : Mrfs
 Source Server Type    : MySQL
 Source Server Version : 80029
 Source Host           : localhost:3306
 Source Schema         : account_cpp

 Target Server Type    : MySQL
 Target Server Version : 80029
 File Encoding         : 65001

 Date: 30/04/2024 15:11:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account_item
-- ----------------------------
DROP TABLE IF EXISTS `account_item`;
CREATE TABLE `account_item`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '姓名',
  `type` int NULL DEFAULT NULL COMMENT '账目类型（1收入；-1支出）',
  `nums` float NULL DEFAULT NULL COMMENT '金额',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of account_item
-- ----------------------------
INSERT INTO `account_item` VALUES (3, '墨染', 1, 8);
INSERT INTO `account_item` VALUES (4, '嘻嘻', 1, 6);
INSERT INTO `account_item` VALUES (5, '墨染', 1, 8);

SET FOREIGN_KEY_CHECKS = 1;

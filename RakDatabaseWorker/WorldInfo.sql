/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "WorldInfo" CASCADE;

CREATE TABLE "WorldInfo" (
  "id" INTEGER NOT NULL PRIMARY KEY,
  "name" TEXT NOT NULL,
  "x" REAL NOT NULL,
  "y" REAL NOT NULL,
  "z" REAL NOT NULL);

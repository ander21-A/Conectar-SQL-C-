CREATE SCHEMA `bd_tienda` ;

CREATE TABLE `bd_tienda`.`productos` (
  `id_producto` INT NOT NULL AUTO_INCREMENT,
  `producto` VARCHAR(50) NULL,
  `id_marca` SMALLINT NULL,
  `descripcion` VARCHAR(100) NULL,
  `precio_costo` DECIMAL(8,2) NULL,
  `precio_venta` DECIMAL(8,2) NULL,
  `existencia` INT NULL,
  `fecha_ingreso` DATETIME NULL,
  PRIMARY KEY (`id_producto`));

CREATE TABLE `bd_tienda`.`marcas` (
  `id_marca` SMALLINT NOT NULL AUTO_INCREMENT,
  `marca` VARCHAR(50) NULL,
  PRIMARY KEY (`id_marca`));

ALTER TABLE `bd_tienda`.`productos` 
ADD INDEX `id_marca_marca_productos_idx` (`id_marca` ASC) VISIBLE;
;
ALTER TABLE `bd_tienda`.`productos` 
ADD CONSTRAINT `id_marca_marca_productos`
  FOREIGN KEY (`id_marca`)
  REFERENCES `bd_tienda`.`marcas` (`id_marca`)
  ON DELETE NO ACTION
  ON UPDATE CASCADE; 
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "customcombobox.h"

CustomComboBox::CustomComboBox(QWidget *parent) : QComboBox(parent) {

	enabled = true;
	fontsize = 9;

	borderColour = "rgba(255,255,255,40)";
	borderWidth = 1;

	setCSS();

}

void CustomComboBox::setEnabled(bool e) {

	enabled = e;

	QComboBox::setEnabled(enabled);

	setCSS();

}

void CustomComboBox::setFontSize(int fsize) {

	fontsize = fsize;
	setCSS();

}

void CustomComboBox::setBorder(int width, QString colour) {

	borderWidth = width;
	borderColour = colour;

	setCSS();

}

void CustomComboBox::setCSS() {

	QString css = "QComboBox {";
	css += QString("border: %1px solid %2;").arg(borderWidth).arg(borderColour);
		css += "background-color: rgb(0,0,0);";
		css += "border-radius: 0px;";
		css += "min-width: 130px;";
		css += QString("font-size: %1pt;").arg(fontsize);
		css += "color: " + QString(enabled ? "white" : "grey") + ";";
	css += "}";

	css += "QComboBox:on {";
		css += "padding-top: 0px;";
		css += "padding-left: 4px;";
	css += "}";

	css += "QComboBox QAbstractItemView {";
		css += "border-radius: 0px;";
		css += "background-color: black;";
		css += "color: " + QString(enabled ? "white" : "grey") + ";";
		css += "selection-background-color: white;";
		css += "selection-color: black;";
	css += "}";


	css += "QComboBox::drop-down::down-arrow {";
		css += "image: url(:/img/empty.png);";
	css += "}";

	css += "QComboBox::drop-down::down-arrow:on {";
		css += "image: url(:/img/empty.png);";
	css += "}";

	this->setStyleSheet(css);

}

CustomComboBox::~CustomComboBox() { }


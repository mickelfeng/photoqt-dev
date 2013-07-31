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

#include "customlabel.h"

CustomLabel::CustomLabel(const QString &text, QWidget *parent) : QLabel(text, parent) {

	css = "QLabel {color: white; } QLabel:disabled { color: grey; }";

	this->setStyleSheet(css);

}

void CustomLabel::setEnabled(bool e) {

	QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect;

	if(e)
		eff->setOpacity(1);
	else
		eff->setOpacity(0.3);

	this->setGraphicsEffect(eff);


	QLabel::setEnabled(e);

}

void CustomLabel::setCSS(QString c) {

	css = c;
	if(this->isEnabled())
		this->setStyleSheet(css + "QLabel { background: rgba(255,255,255,200); }");
	else
		this->setStyleSheet(css + "QLabel { background: transparent; }");

}

CustomLabel::~CustomLabel() { }

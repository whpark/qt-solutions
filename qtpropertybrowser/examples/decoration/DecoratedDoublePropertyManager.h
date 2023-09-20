// Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "qtpropertybrowser.h"
#include "qteditorfactory.h"
#include "qttreepropertybrowser.h"

class DecoratedDoublePropertyManager : public QtDoublePropertyManager
{
    Q_OBJECT
public:
    DecoratedDoublePropertyManager(QObject *parent = 0);
    ~DecoratedDoublePropertyManager();

    QString prefix(const QtProperty *property) const;
    QString suffix(const QtProperty *property) const;
public Q_SLOTS:
    void setPrefix(QtProperty *property, const QString &prefix);
    void setSuffix(QtProperty *property, const QString &suffix);
Q_SIGNALS:
    void prefixChanged(QtProperty *property, const QString &prefix);
    void suffixChanged(QtProperty *property, const QString &suffix);
protected:
    QString valueText(const QtProperty *property) const;
    virtual void initializeProperty(QtProperty *property);
    virtual void uninitializeProperty(QtProperty *property);
private:
    struct Data {
        QString prefix;
        QString suffix;
    };
    QMap<const QtProperty *, Data> propertyToData;
};


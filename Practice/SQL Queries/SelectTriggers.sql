USE MSUDB
GO
SELECT schemaName = s.name,
       objectName = o.name,
       triggerName = tr.name
FROM sys.triggers tr
JOIN sys.objects o ON o.object_id = tr.parent_id
JOIN sys.schemas s ON s.schema_id = o.schema_id
WHERE tr.parent_class_desc = 'OBJECT_OR_COLUMN'
ORDER BY s.name, o.name, tr.name;

{
  crawl for all XTELs (doors)
}
unit dumpxtel;

function Process(e: IInterface): integer;
var
  xtel, edid, fid, name: string;
  xelement, xrec, xfid: IwbElement;
begin

  if not ElementExists(e, 'XTEL') then begin
    Exit;
  end;

  {xelement := ElementByName(e, 'XTEL');}
  xelement := ElementByPath(e, 'XTEL - Teleport Destination');
  xrec := ElementByPath(e, 'Record Header');

  name := GetElementEditValues(e, 'NAME - Base');
{  edid := GetElementEditValues(e, 'EDID - Editor ID');}
  fid := GetElementEditValues(xrec, 'FormID');
  xtel := GetElementEditValues(xelement, 'Door');

  AddMessage('name ::: ' + name);
  AddMessage('             edid ::: ' + edid);
  AddMessage(' (from door) fid  ::: ' + fid);
  AddMessage(' (to door)   xtel ::: ' + xtel);

end;
end.

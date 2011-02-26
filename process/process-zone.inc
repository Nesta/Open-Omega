<?php
$zone = $vars['zone'];

foreach($vars['regions'] AS $region_id => $region) {
  $vars['regions'][$region_id]['#omega']['page_data']['addthis'] = $vars['addthis'];
}
if ($zone['zid'] == 'content') {
  //krumo($vars);
}